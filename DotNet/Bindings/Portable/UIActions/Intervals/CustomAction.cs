using Urho.Gui;
namespace Urho.UIActions
{
	using FiniteTimeActionStateDelegate = System.Func<FiniteTimeAction, UIElement , FiniteTimeActionState >;
	public class CustomAction : FiniteTimeAction
	{
		

		FiniteTimeActionStateDelegate _finiteTimeActionStateDelegate;

		#region Constructors

		public CustomAction (float duration, FiniteTimeActionStateDelegate finiteTimeActionStateDelegate) : base (duration)
		{
			_finiteTimeActionStateDelegate = finiteTimeActionStateDelegate;
		}

		#endregion Constructors


		protected internal override ActionState StartAction(UIElement target)
		{
			FiniteTimeActionState state =  _finiteTimeActionStateDelegate?.Invoke(this, target);
			// The assumption is that _finiteTimeActionStateDelegate will return a valid FiniteTimeActionState  
			// In case it'zs not then return a dummy CustomActionState
			return (state != null) ? state : new CustomActionState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new CustomAction (Duration, _finiteTimeActionStateDelegate);
		}
	}

	public class CustomActionState : FiniteTimeActionState
	{

		public CustomActionState (CustomAction action, UIElement target)
			: base (action, target)
		{ 
		
		}

		public override void Update (float time)
		{
	
		}

		protected internal override void Stop ()
		{
			base.Stop ();
		}

	}
}