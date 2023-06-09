using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseElasticOut : EaseElastic
	{
		#region Constructors

		public EaseElasticOut (FiniteTimeAction action) : base (action, 0.3f)
		{
		}

		public EaseElasticOut (FiniteTimeAction action, float period) : base (action, period)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseElasticOutState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new EaseElasticIn ((FiniteTimeAction)InnerAction.Reverse(), Period);
		}
	}


	#region Action state

	public class EaseElasticOutState : EaseElasticState
	{
		public EaseElasticOutState (EaseElasticOut action, UIElement target) : base (action, target)
		{
		}

		public override void Update (float time)
		{
			InnerActionState.Update (EaseMath.ElasticOut (time, Period));
		}
	}

	#endregion Action state
}