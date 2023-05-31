using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseInOut : EaseRateAction
	{
		#region Constructors

		public EaseInOut (FiniteTimeAction action, float rate) : base (action, rate)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseInOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseInOut ((FiniteTimeAction)InnerAction.Reverse (), Rate);
		}
	}


	#region Action state

	public class EaseInOutState : EaseRateActionState
	{
		public EaseInOutState (EaseInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			float actionRate = Rate;
			time *= 2;

			if (time < 1)
			{
				InnerActionState.Update (0.5f * (float)Math.Pow (time, actionRate));
			}
			else
			{
				InnerActionState.Update (1.0f - 0.5f * (float)Math.Pow (2 - time, actionRate));
			}        
		}
	}

	#endregion Action state
}