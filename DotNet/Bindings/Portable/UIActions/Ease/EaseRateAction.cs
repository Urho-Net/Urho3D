using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseRateAction : ActionEase
	{
		public float Rate { get; private set; }


		#region Constructors

		public EaseRateAction (FiniteTimeAction action, float rate) : base (action)
		{
			Rate = rate;
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseRateActionState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseRateAction ((FiniteTimeAction)InnerAction.Reverse (), 1 / Rate);
		}
	}


	#region Action state

	public class EaseRateActionState : ActionEaseState
	{
		protected float Rate { get; private set; }

		public EaseRateActionState (EaseRateAction action, UIElement target) : base (action, target)
		{
			Rate = action.Rate;
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.ExponentialOut (time));
		}
	}

	#endregion Action state
}