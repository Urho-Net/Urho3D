
using System;

[AttributeUsage(AttributeTargets.All)]
public sealed class PreserveAttribute : System.Attribute
{
	public bool AllMembers;
	public bool Conditional;
}