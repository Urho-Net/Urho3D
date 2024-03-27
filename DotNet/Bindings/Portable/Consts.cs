using System;
using System.Runtime.InteropServices;

namespace Urho
{
	internal static class Consts
	{
#if __IOS__ && __XAMARIN__
		public const string NativeImport = "__Internal";
#else
		public const string NativeImport = "Urho3D";
#endif
	}
}
