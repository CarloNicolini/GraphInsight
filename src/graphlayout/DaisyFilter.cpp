/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include "DaisyFilter.h"

/**
 * @ingroup GraphLayout
 * @brief Create a linear FIR or IIR filter
 *
 * @param ffOrder the "feed forward" or FIR order
 * @param ffGains the "feed forward" or FIR gains
 * @param fbOrder the "feed back" or IIR order
 * @param fbGains the "feed back" or IIR gains
 *
 * IMPORTANT: If "ffGains" is not an array of at least "ffOrder" length, or likewise "fbGains" is not an array
 * of at least "fbOrder" length, you WILL get serious errors!
 **/
DaisyFilter::DaisyFilter(int ffOrder, const double *ffGains, int fbOrder, const double *fbGains) :
    mInputs(ffOrder), mOutputs(fbOrder)
{  mInputOrder = ffOrder;
    mOutputOrder = fbOrder;

    if( ffOrder > 0 )
    {  mInputGains = new double[ffOrder];
    }
    if( fbOrder > 0 )
    {  mOutputGains = new double[fbOrder];
    }

    for( int i = 0; i < ffOrder; i++ )
    {  mInputGains[i] = ffGains[i];
        mInputs[i] = 0.0f;
    }

    for( int i = 0; i < fbOrder; i++ )
    {  mOutputGains[i] = fbGains[i];
        mOutputs[i] = 0.0f;
    }
}

/**
* @ingroup GraphLayout
* Destructor
**/
DaisyFilter::~DaisyFilter()
{  if( mInputOrder > 0 )
    {  delete[] mInputGains;
    }
    if( mOutputOrder > 0 )
    {  delete[] mOutputGains;
    }
}

/**
 * @ingroup GraphLayout
 * @brief Creates a one-pole IIR low-pass filter of the form  y[n] = gain*x[n] + (1-gain)*y[n-1]
 * This filter is stable for gains in the range [0,1]
 * @param gain The filter's feedforward gain factor (lower = smoother but slower)
**/
DaisyFilter* DaisyFilter::SinglePoleIIRFilter(double gain)
{  double ffGain = gain;
    double fbGain = gain - 1.0f;

    static DaisyFilter ret = DaisyFilter(1, &ffGain, 1, &fbGain);
    return &ret;
}

/**
 * @ingroup GraphLayout
 *
 * @brief Creates a K-tap FIR moving average filter of the form  y[n] = 1/k * (x[k] + x[k-1] + ... + x[0])
 *
 * This filter is always stable.
 *
 * @param taps The number of samples to average over.  Higher = smoother but slower.
 **/
DaisyFilter* DaisyFilter::MovingAverageFilter(int taps)
{  if( taps < 1 )
    {  taps = 1;
    }

    double *gains = new double[taps];

    double gain = 1.0f/(double)taps;

    for( int i = 0; i < taps; i++ )
    {  gains[i] = gain;
    }

    static DaisyFilter ret =  DaisyFilter(taps, &gains[0], 0, (double *)0);
    delete[] gains;
    return &ret;
}

/**
 * @ingroup GraphLayout
 * @brief Creates a standard PID controller of the form  y[n] = y[n-1] + (Kp+Ki+Kd)*x[n] + (Kp-2*Kd)*x[n-1] + Kd*x[n-2]
 * In order to use this as a PID controller, make sure you call Calculate() with the error (difference between
 * a desired reading and the current one) as the input.
 * Note that this has no considerations for:
 *  - Integral windup
 *  - Derivitive term misbehavior
 * As such, it might not be as useful as a full-featured PID class.  But it's included here to demonstrate the
 * power of linear filters!
 * Stability of this filter is completely dependent on the gains (and system dynamics!)
 *
 * @param Kp The proportional gain
 * @param Ki The integral gain
 * @param Kd The derivative gain
 */
DaisyFilter* DaisyFilter::PIDFilter(double Kp, double Ki, double Kd)
{  double ffGains[] = {Kp+Ki+Kd, Kp-2*Kd, Kd};
    double fbGains[] = {-1};

    static DaisyFilter ret = DaisyFilter(3, &ffGains[0], 1, &fbGains[0]);
    return  &ret;
}

/**
 * @ingroup GraphLayout
 * @brief Calculates the next value of the filter.
 * NOTE: Obviously, the rate at which this function is called is important and currently not compensated for.
 * Changing the update rate WILL require gains to be adjusted.
 * @param value the current input value.
 * @return the filtered value at this step.
 */
double DaisyFilter::Calculate(double value)
{  double retVal = 0.0;

    // Rotate the inputs
    if( mInputOrder > 0 )
    {  mInputs.Increment();
        mInputs[0] = value;
    }

    // Calculate the new value
    for( int i = 0; i < mInputOrder; i++ )
    {  retVal += mInputs[i]*mInputGains[i];
    }
    for( int i = 0; i < mOutputOrder; i++ )
    {  retVal -= mOutputs[i]*mOutputGains[i];
    }

    // Rotate the outputs
    if( mOutputOrder > 0 )
    {  mOutputs.Increment();
        mOutputs[0] = retVal;
    }

    return retVal;
}
