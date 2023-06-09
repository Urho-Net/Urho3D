﻿using System;
using System.Threading.Tasks;
using Urho.Gui;
namespace Urho.UIActions
{
	internal class TaskSource : ActionInstant
	{
		public TaskCompletionSource<ActionState> TaskCompletionSource { get; }

		#region Constructors

		public TaskSource()
		{
			TaskCompletionSource = null;
		}

		public TaskSource(TaskCompletionSource<ActionState> taskSource) : base()
		{
			TaskCompletionSource = taskSource;
		}

		#endregion Constructors

		protected internal override ActionState StartAction(UIElement target)
		{
			return new TaskSourceState (this, target);
		}
	}

	internal class TaskSourceState : ActionInstantState
	{
		TaskCompletionSource<ActionState> TaskCompletionSource { get; set;}

		public TaskSourceState (TaskSource action, UIElement target)
			: base(action, target)
		{
			TaskCompletionSource = action.TaskCompletionSource;
		}

		public override void Update (float time) => SetResult();

		public void SetResult() => TaskCompletionSource.TrySetResult(this);

		public void Cancel() => TaskCompletionSource.TrySetCanceled();
	}
}