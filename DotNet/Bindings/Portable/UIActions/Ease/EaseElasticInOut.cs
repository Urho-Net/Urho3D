using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseElasticInOut : EaseElastic
	{
		#region Constructors

		public EaseElasticInOut (FiniteTimeAction action) : this (action, 0.3f)
		{
		}

		public EaseElasticInOut (FiniteTimeAction action, float period) : base (action, period)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseElasticInOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseElasticInOut ((FiniteTimeAction)InnerAction.Reverse (), Period);
		}
	}


	#region Action state

	public class EaseElasticInOutState : EaseElasticState
	{
		public EaseElasticInOutState (EaseElasticInOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.ElasticInOut (time, Period));
		}
	}

	#endregion Action state
}