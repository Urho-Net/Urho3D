using Urho.Gui;

namespace Urho.UIActions
{
	public class JumpBy : FiniteTimeAction
	{   
		#region Properties

		public uint Jumps { get; protected set; }
		public float Height { get; protected set; }
		public Vector2 Position { get; protected set; }

		#endregion Properties


		#region Constructors

		public JumpBy (float duration, Vector2 position, float height, uint jumps) : base (duration)
		{
			Position = position;
			Height = height;
			Jumps = jumps;
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new JumpByState (this, target);
		}

		public override FiniteTimeAction Reverse ()
		{
			return new JumpBy (Duration, new Vector2 (-Position.X, -Position.Y), Height, Jumps);
		}
	}

	public class JumpByState : FiniteTimeActionState
	{
		protected Vector2 Delta;
		protected float Height;
		protected uint Jumps;
		protected Vector2 StartPosition;
		protected Vector2 P;

		public JumpByState (JumpBy action, UIElement target)
			: base (action, target)
		{ 
			Delta = action.Position;
			Height = action.Height;
			Jumps = action.Jumps;
			P = StartPosition = target.Position.CastF();
		}

		public override void Update (float time)
		{
			if (Target != null)
			{
				// Is % equal to fmodf()???
				float frac = (time * Jumps) % 1f;
				float y = Height * 4f * frac * (1f - frac);
				y += Delta.Y * time;
				float x = Delta.X * time;

				Vector2 currentPos = Target.Position.CastF();

				Vector2 diff = currentPos - P;
				StartPosition = diff + StartPosition;

				Vector2 newPos = StartPosition + new Vector2 (x, y);
				Target.Position = newPos.CastI();

				P = newPos;
			}
		}
	}

}