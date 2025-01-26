@extends('layouts.app')

@section('content')
    <h1 class="text-white">Add New Gym</h1>

    <form action="{{ route('gyms.store') }}" method="POST">
        @csrf
        <label class="text-white">Name:</label>
        <input type="text" name="name" required>
        <br>
        <label class="text-white">Address:</label>
        <input type="text" name="address" required>
        <br>
        <button type="submit" class="text-white">Add Gym</button>
    </form>
@endsection
