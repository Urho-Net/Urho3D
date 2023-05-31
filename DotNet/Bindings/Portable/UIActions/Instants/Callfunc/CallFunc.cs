﻿using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class CallFunc : ActionInstant
	{
		public Action CallFunction { get; }
		public string ScriptFuncName { get; }

		#region Constructors

		public CallFunc()
		{
			ScriptFuncName = "";
			CallFunction = null;
		}

		public CallFunc(Action selector) : base()
		{
			CallFunction = selector;
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new CallFuncState (this, target);
		}
	}

	public class CallFuncState : ActionInstantState
	{
		protected Action CallFunction { get; set;}
		protected string ScriptFuncName { get; set; }

		public CallFuncState (CallFunc action, UIElement target)
			: base(action, target)
		{   
			CallFunction = action.CallFunction;
			ScriptFuncName = action.ScriptFuncName;
		}

		public virtual void Execute()
		{
			CallFunction?.Invoke();
		}

		public override void Update (float time)
		{
			Execute();
		}
	}
}