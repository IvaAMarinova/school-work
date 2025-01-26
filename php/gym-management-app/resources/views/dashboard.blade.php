@extends('layouts.app')

@section('content')
    <div class="container">
        <h1 class="text-white">Dashboard</h1>
        <p class="text-white">Welcome, {{ Auth::user()->name }}!</p>

        <div class="button-group">
            <div class="grid grid-cols-1 gap-4 sm:grid-cols-3">
                <a href="{{ route('gyms.index') }}" class="bg-blue-500 text-white px-4 py-2 rounded-md text-center">
                    Manage Gyms
                </a>
                <a href="{{ route('class-sessions.index') }}" class="bg-green-500 text-white px-4 py-2 rounded-md text-center">
                    Manage Class Sessions
                </a>
                <a href="{{ route('attendances.index') }}" class="bg-purple-500 text-white px-4 py-2 rounded-md text-center">
                    Manage Attendance
                </a>
            </div>
        </div>
    </div>
@endsection
