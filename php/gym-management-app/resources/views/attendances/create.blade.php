@extends('layouts.app')

@section('content')
    <h1 class="text-white">Add New Attendance</h1>

    <form  class="text-white" action="{{ route('attendances.store') }}" method="POST">
        @csrf
        <label>User:</label>
        <select name="user_id" required>
            @foreach ($users as $user)
                <option value="{{ $user->id }}">{{ $user->name }}</option>
            @endforeach
        </select>
        <br>
        <label>Class Session:</label>
        <select name="class_session_id" required>
            @foreach ($classSessions as $classSession)
                <option value="{{ $classSession->id }}">{{ $classSession->session_name }}</option>
            @endforeach
        </select>
        <br>
        <label>Status:</label>
        <select name="status" required>
            <option value="present">Present</option>
            <option value="absent">Absent</option>
        </select>
        <br>
        <button type="submit">Add Attendance</button>
    </form>
@endsection
