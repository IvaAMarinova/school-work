@extends('layouts.app')

@section('content')
    <h1 class="text-white" >Attendance Records</h1>
    <a class="text-white"  href="{{ route('attendances.create') }}">Add New Attendance</a>

    <table class="text-white" >
        <thead>
            <tr>
                <th>User</th>
                <th>Class Session</th>
                <th>Status</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
            @foreach ($attendances as $attendance)
                <tr>
                    <td>{{ $attendance->user->name }}</td>
                    <td>{{ $attendance->classSession->session_name }}</td>
                    <td>{{ $attendance->status }}</td>
                    <td>
                        <a href="{{ route('attendances.edit', $attendance->id) }}">Edit</a>
                        <form action="{{ route('attendances.destroy', $attendance->id) }}" method="POST" style="display: inline;">
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
