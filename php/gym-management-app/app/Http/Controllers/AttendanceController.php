<?php

namespace App\Http\Controllers;

use App\Models\Attendance;
use Illuminate\Http\Request;

class AttendanceController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $attendances = Attendance::all();

        return view('attendances.index', compact('attendances'));
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        $users = \App\Models\User::all(); // Fetch all users
        $classSessions = \App\Models\ClassSession::all(); // Fetch all class sessions

        return view('attendances.create', compact('users', 'classSessions'));
    }


    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        Attendance::create($request->all());

        return redirect()->route('attendances.index');
    }

    /**
     * Display the specified resource.
     */
    public function show(Attendance $attendance)
    {
        return view('attendances.show', compact('attendance'));
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Attendance $attendance)
    {
        $users = \App\Models\User::all(); // Fetch all users
        $classSessions = \App\Models\ClassSession::all(); // Fetch all class sessions

        return view('attendances.edit', compact('attendance', 'users', 'classSessions'));
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Attendance $attendance)
    {
        $attendance->update($request->all());

        return redirect()->route('attendances.index');
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Attendance $attendance)
    {
        $attendance->delete();

        return redirect()->route('attendances.index');
    }
}
