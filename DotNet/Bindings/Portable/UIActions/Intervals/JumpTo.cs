using Urho.Gui;

namespace Urho.UIActions
{
	public class JumpTo : JumpBy
	{
		#region Constructors

		public JumpTo (float duration, Vector2 position, float height, uint jumps) 
			: base (duration, position, height, jumps)
		{
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new JumpToState (this, target);

		}

	}

	public class JumpToState : JumpByState
	{

		public JumpToState (JumpBy action, UIElement target)
			: base (action, target)
		{ 
			Delta = new Vector2 (Delta.X - StartPosition.X, Delta.Y - StartPosition.Y);
		}
	}

}