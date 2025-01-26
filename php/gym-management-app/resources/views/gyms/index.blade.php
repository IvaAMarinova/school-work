@extends('layouts.app')

@section('content')
    <h1 class="text-white">Gyms</h1>
    <a class="text-white" href="{{ route('gyms.create') }}">Add New Gym</a>

    <table>
        <thead>
            <tr>
                <th class="text-white">Name</th>
                <th class="text-white">Address</th>
                <th class="text-white">Actions</th>
            </tr>
        </thead>
        <tbody>
            @foreach ($gyms as $gym)
                <tr class="text-white">
                    <td>{{ $gym->name }}</td>
                    <td>{{ $gym->address }}</td>
                    <td>
                        <a href="{{ route('gyms.edit', $gym->id) }}">Edit</a>
                        <form action="{{ route('gyms.destroy', $gym->id) }}" method="POST" style="display: inline;">
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
