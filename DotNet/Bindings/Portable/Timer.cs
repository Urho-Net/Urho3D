using Urho;
using System;

namespace Urho
{
    public class Timer
    {
        public Timer()
        {
            Reset();
        }

        public uint GetMSec(bool reset)
        {
            long currentTime = Tick();
            long elapsedTime = currentTime - startTime_;
            if (reset)
                startTime_ = currentTime;

            return (uint)elapsedTime;
        }
        /// Reset the timer.
        public void Reset()
        {
            startTime_ = Tick();
        }

        static long Tick()
        {
            return DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();

        }

        /// Starting clock value in milliseconds.
        long startTime_;

    }

}
