@extends('layouts.app')

@section('content')
    <h1 class="text-white">Edit Gym</h1>

    <form action="{{ route('gyms.update', $gym->id) }}" method="POST">
        @csrf
        @method('PUT')
        <label class="text-white">Name:</label>
        <input type="text" name="name" value="{{ $gym->name }}" required>
        <br>
        <label class="text-white">Address:</label>
        <input type="text" name="address" value="{{ $gym->address }}" required>
        <br>
        <button type="submit" class="text-white">Update Gym</button>
    </form>
@endsection
