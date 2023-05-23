using System;

namespace Urho
{
	public static class LogSharp // TODO: remove
	{
		public static LogSharpLevel LogLevel { get; set; } = LogSharpLevel.Debug;

		public static void Error(string str, Exception exc = null) => Write(LogSharpLevel.Error, $"Exception: {exc}. " + str);
		public static void Warn(string str) => Write(LogSharpLevel.Warn, str);
		public static void Debug(string str) => Write(LogSharpLevel.Debug, str);
		public static void Trace(string str) => Write(LogSharpLevel.Trace, str);

		static void Write(LogSharpLevel level, string str)
		{
			if (level < LogLevel)
				return;
#if __ANDROID__
			Urho.IO.Log.Write(Urho.LogLevel.Warning,str);
#else
			System.Console.WriteLine($"{level}: {str}");
#endif
		}

	}

	public enum LogSharpLevel
	{
		Trace,
		Debug,
		Warn,
		Error
	}
}
