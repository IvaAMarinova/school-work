@extends('layouts.app')

@section('content')
    <h1 class="text-white" >Class Sessions</h1>
    <a  class="text-white" href="{{ route('class-sessions.create') }}">Add New Class Session</a>

    <table class="text-white" >
        <thead>
            <tr>
                <th>Session Name</th>
                <th>Schedule</th>
                <th>Gym</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody class="text-white">
            @foreach ($classSessions as $classSession)
                <tr>
                    <td>{{ $classSession->session_name }}</td>
                    <td>{{ $classSession->schedule }}</td>
                    <td>{{ $classSession->gym->name }}</td>
                    <td>
                        <a href="{{ route('class-sessions.edit', $classSession->id) }}">Edit</a>
                        <form action="{{ route('class-sessions.destroy', $classSession->id) }}" method="POST" style="display: inline;">
                            @csrf
                            @method('DELETE')
                            <button type="submit" onclick="return confirm('Are you sure?')">Delete</button>
                        </form>
                    </td>
                </tr>
            @endforeach
        </tbody>
    </table>
@endsection
