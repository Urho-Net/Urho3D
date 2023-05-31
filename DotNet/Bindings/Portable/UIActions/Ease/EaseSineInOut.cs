using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseSineInOut : ActionEase
	{
		#region Constructors

		public EaseSineInOut (FiniteTimeAction action) : base (action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseSineInOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseSineInOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseSineInOutState : ActionEaseState
	{
		public EaseSineInOutState (EaseSineInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.SineInOut (time));
		}
	}

	#endregion Action state
}