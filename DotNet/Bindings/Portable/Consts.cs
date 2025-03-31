using System;
using System.Runtime.InteropServices;

namespace Urho
{
	internal static class Consts
	{
#if __IOS__
		public const string NativeImport = "@rpath/Urho3D.framework/Urho3D";
#else
		public const string NativeImport = "Urho3D";
#endif
	}
}
