@extends('layouts.app')

@section('content')
    <h1 class="text-white">Edit Class Session</h1>

    <form class="text-white" action="{{ route('class-sessions.update', $classSession->id) }}" method="POST">
        @csrf
        @method('PUT')
        <label>Session Name:</label>
        <input type="text" name="session_name" value="{{ $classSession->session_name }}" required>
        <br>
        <label>Schedule:</label>
        <input type="datetime-local" name="schedule" value="{{ $classSession->schedule }}" required>
        <br>
        <label>Gym:</label>
        <select name="gym_id" required>
            @foreach ($gyms as $gym)
                <option value="{{ $gym->id }}" @if ($classSession->gym_id == $gym->id) selected @endif>{{ $gym->name }}</option>
            @endforeach
        </select>
        <br>
        <button type="submit">Update Class Session</button>
    </form>
@endsection
