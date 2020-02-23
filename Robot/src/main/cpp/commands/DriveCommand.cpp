/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ControllerState.h"
#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem *subsystem)
    : m_subsystem{subsystem} 
{
}


// ***** public methods *****

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
    // get state of xbox controller controls
    g_controller0->GetState();

    // get raw joystick values and +- sign
    //this pulls the joystick values into the program.
    //(gets the state) gets what you want to do
    float leftX =  -g_controller0->GetLeftY();
    float rightX = g_controller0->GetRightY();

    //if the joystick values are almost the same, make them the same to make driving straight easier.
    //The issue was that slight input on the right stick would stop or slow down the input on the left side, and vice versa.
    if (Equals(leftX, rightX, .2)) // Threshold value was changed to correct an issue.
    {
        rightX = leftX;
   	}

    // compute the adjusted motor values based n joystick / motor curve
    //this takes the value and matches it with the closest value on our parabola
    //so that the driving is smoother
    float leftY = SignOf(leftX) * SmoothDriveCurve(fabs(leftX));
    float rightY = SignOf(rightX) * SmoothDriveCurve(fabs(rightX));

    if (g_controller0->GetLeftBumper()) // Invert drive code
    {
        float temp = leftY;
        leftY = rightY;
        rightY = temp;
    }

    // Enable vision assisted targeting
    // B button on main controller
    if (g_controller0->GetButtonB())
    {
        // Error as target approaches 0
        double k_error = m_subsystem->GetLimeHorizontalOffset();
        
        // As the bot approaches the target, the motor power will get lower.
        // The error max is -27/27 and the min is 0.
        // Make sure the motor output for both min/max are high
        // enough as low motor power will make them not turn.
        
        // Motor output at min error
        double k_min_pow = 0.5;
        
        // Motor output at max error
        double k_max_pow = 0.9;

        // Sign (+/-) of the error
        double k_sign = k_error >= 0 ? 1.0 : -1.0;
        
        // Calculate the output (Desmos: https://www.desmos.com/calculator/mxfs6w0vzx)
        double k_output = k_sign * (((k_min_pow-k_max_pow)/(-27.0)) * fabs(k_error) + k_min_pow);

        // Stop the motors when we are within 0.5 degrees.
        if (fabs(k_error) <= 0.5)
            k_output = 0;


        leftY = (k_output);
        rightY = -(k_output);
    }
    

    // motor gain value - used to slow down drive system for new drivers
    // always >= .4 and <= 1.0!!!
    // Turbo mode
    double gain = (g_controller0->GetRightTrig() > 0.2 ? 1.0 : 0.8);

    //printf("left motor = %3.2f right motor = %3.2f\n", gain*leftY, gain*rightY);

    m_subsystem->SetLeftSpeed(gain * leftY);
    m_subsystem->SetRightSpeed(gain * rightY);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
    return false;
}


// ***** private methods *****

double DriveCommand::SmoothDriveCurve(double joystickYPosition) const
{
    if (joystickYPosition < .05)
    {
        return 0.0; // allow for joystick calibration error
    }

    // data points on drive curve parabola
    double x2 = .5, y2 = .5, y3 = 1.0;

    // variable a=a in equation b=b in equation
    //ax^2+bx+c the Equation for a parabola
    double b = ((y3 * x2 * x2) - y2) / ((x2 * x2) - x2);
    double a = y3 - b;

    // Returns the corresponding motor speed
    return (a * joystickYPosition * joystickYPosition) + (b * joystickYPosition);
}
