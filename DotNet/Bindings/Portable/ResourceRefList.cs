using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;
using System.Runtime.InteropServices;
using Urho.Physics;
using Urho.Gui;
using Urho.Urho2D;
using Urho.Resources;
using Urho.IO;

namespace Urho
{
    public partial class ResourceRefList
    {
        /// Object type.
        public StringHash Type = new StringHash();
        /// List of object names.
        public StringVector Names = new StringVector();
    }
}