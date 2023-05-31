using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseExponentialInOut : ActionEase
	{
		#region Constructors

		public EaseExponentialInOut (FiniteTimeAction action) : base(action)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseExponentialInOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseExponentialInOut ((FiniteTimeAction)InnerAction.Reverse ());
		}
	}


	#region Action state

	public class EaseExponentialInOutState : ActionEaseState
	{
		public EaseExponentialInOutState (EaseExponentialInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.ExponentialInOut (time));
		}
	}

	#endregion Action state
}