<?php

namespace App\Http\Controllers;

use App\Models\ClassSession;
use Illuminate\Http\Request;

class ClassSessionController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $classSessions = ClassSession::all();

        return view('class-sessions.index', compact('classSessions'));
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        $gyms = \App\Models\Gym::all(); // Fetch all gyms
        return view('class-sessions.create', compact('gyms'));
    }


    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        ClassSession::create($request->all());

        return redirect()->route('class-sessions.index');
    }

    /**
     * Display the specified resource.
     */
    public function show(ClassSession $classSession)
    {
        return view('class-sessions.show', compact('classSession'));
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit($id)
    {
        $classSession = \App\Models\ClassSession::findOrFail($id); // Fetch the class session
        $gyms = \App\Models\Gym::all(); // Fetch all gyms

        return view('class-sessions.edit', compact('classSession', 'gyms'));
    }


    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, ClassSession $classSession)
    {
        $classSession->update($request->all());

        return redirect()->route('class-sessions.index');
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(ClassSession $classSession)
    {
        $classSession->delete();

        return redirect()->route('class-sessions.index');
    }
}
