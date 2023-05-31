using System;

using Urho.Gui;
namespace Urho.UIActions
{
	public class RemoveSelf : ActionInstant
	{
		protected internal override ActionState StartAction(UIElement target)
		{
			return new RemoveSelfState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			throw new NotSupportedException();
		}
	}

	public class RemoveSelfState : ActionInstantState
	{
		public RemoveSelfState (RemoveSelf action, UIElement target)
			: base (action, target)
		{   
		}

		public override void Update (float time)
		{
            if (Target.Parent != null)
            {
				Target.OnRemoving();
                Target.Parent.RemoveChild(Target);
            }
		}
	}
}