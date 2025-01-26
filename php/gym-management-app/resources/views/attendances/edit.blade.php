@extends('layouts.app')

@section('content')
    <h1 class="text-white">Edit Attendance</h1>

    <form class="text-white" action="{{ route('attendances.update', $attendance->id) }}" method="POST">
        @csrf
        @method('PUT')
        <label>User:</label>
        <select name="user_id" required>
            @foreach ($users as $user)
                <option value="{{ $user->id }}" @if ($attendance->user_id == $user->id) selected @endif>{{ $user->name }}</option>
            @endforeach
        </select>
        <br>
        <label>Class Session:</label>
        <select name="class_session_id" required>
            @foreach ($classSessions as $classSession)
                <option value="{{ $classSession->id }}" @if ($attendance->class_session_id == $classSession->id) selected @endif>{{ $classSession->session_name }}</option>
            @endforeach
        </select>
        <br>
        <label>Status:</label>
        <select name="status" required>
            <option value="present" @if ($attendance->status == 'present') selected @endif>Present</option>
            <option value="absent" @if ($attendance->status == 'absent') selected @endif>Absent</option>
        </select>
        <br>
        <button type="submit">Update Attendance</button>
    </form>
@endsection
