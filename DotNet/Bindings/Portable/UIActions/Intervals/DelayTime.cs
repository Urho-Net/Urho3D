using Urho.Gui;
namespace Urho.UIActions
{
	public class DelayTime : FiniteTimeAction
	{
		#region Constructors

		public DelayTime (float duration) : base (duration)
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new DelayTimeState (this, target);

		}

		public override FiniteTimeAction Reverse ()
		{
			return new DelayTime (Duration);
		}
	}

	public class DelayTimeState : FiniteTimeActionState
	{

		public DelayTimeState (DelayTime action, UIElement target)
			: base (action, target)
		{
		}

		public override void Update (float time)
		{
		}
	}
}