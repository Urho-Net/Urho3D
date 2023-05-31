using Urho.Gui;
namespace Urho.UIActions
{
	public class EaseElastic : ActionEase
	{
		public float Period { get; private set; }


		#region Constructors

		public EaseElastic (FiniteTimeAction action, float period) : base (action)
		{
			Period = period;
		}

		public EaseElastic (FiniteTimeAction action) : this (action, 0.3f)
		{
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			return new EaseElasticState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return null;
		}
	}


	#region Action state

	public class EaseElasticState : ActionEaseState
	{
		protected float Period { get; private set; }

		public EaseElasticState (EaseElastic action, UIElement target) : base (action, target)
		{
			Period = action.Period;
		}
	}

	#endregion Action state
}