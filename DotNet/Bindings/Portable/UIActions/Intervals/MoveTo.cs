using Urho.Gui;

namespace Urho.UIActions
{
	public class MoveTo : MoveBy
	{
		protected Vector2 EndPosition;

		#region Constructors

		public MoveTo (float duration, Vector2 position) : base (duration, position)
		{
			EndPosition = position;
		}

		#endregion Constructors

		public Vector2 PositionEnd {
			get { return EndPosition; }
		}

		protected internal override ActionState StartAction(UIElement target)
		{
			return new MoveToState (this, target);
		}
	}

	public class MoveToState : MoveByState
	{
		public MoveToState (MoveTo action, UIElement target)
			: base (action, target)
		{ 
			StartPosition = target.Position.CastF();
			PositionDelta = action.PositionEnd - target.Position.CastF();
		}

		public override void Update (float time)
		{
			if (Target != null)
			{
				Vector2 newPos = StartPosition + PositionDelta * time;
				Target.Position = newPos.CastI();
				PreviousPosition = newPos;
			}
		}
	}
}