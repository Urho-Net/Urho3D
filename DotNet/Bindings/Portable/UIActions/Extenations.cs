using System;
using System.Collections.Generic;
using Urho;

namespace Urho.UIActions
{
    public static class Extentions
    {

        public static Vector2 CastF(this IntVector2 vec)
        {
            return new Vector2(vec.X, vec.Y);
        }

        public static IntVector2 CastI(this Vector2 vec)
        {
            return new IntVector2((int)vec.X, (int)vec.Y);
        }
    }

}