@extends('layouts.app')

@section('content')
    <h1 class="text-white">Add New Class Session</h1>

    <form action="{{ route('class-sessions.store') }}" method="POST">
        @csrf
        <label class="text-white">Session Name:</label>
        <input type="text" name="session_name" required>
        <br>
        <label class="text-white">Schedule:</label>
        <input type="datetime-local" name="schedule" required>
        <br>
        <label class="text-white">Gym:</label>
        <select name="gym_id" required>
            @foreach ($gyms as $gym)
                <option value="{{ $gym->id }}">{{ $gym->name }}</option>
            @endforeach
        </select>
        <br>
        <button type="submit">Add Class Session</button>
    </form>
@endsection
