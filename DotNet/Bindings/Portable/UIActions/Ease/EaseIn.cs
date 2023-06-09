using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseIn : EaseRateAction
	{
		#region Constructors

		public EaseIn (FiniteTimeAction action, float rate) : base (action, rate)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseInState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseIn ((FiniteTimeAction)InnerAction.Reverse (), 1 / Rate);
		}
	}


	#region Action state

	public class EaseInState : EaseRateActionState
	{
		public EaseInState (EaseIn action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update ((float)Math.Pow (time, Rate));
		}
	}

	#endregion Action state

}