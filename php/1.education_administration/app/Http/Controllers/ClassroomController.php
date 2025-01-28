<?php

namespace App\Http\Controllers;

use App\Http\Requests\ClassroomRequest;
use App\Http\Requests\UpdateClassroomRequest;
use App\Models\Classroom;
use App\Models\School;

class ClassroomController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index(School $school)
    {
        return response()->json($school->classrooms);
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(School $school, ClassroomRequest $request)
    {
        $classroom = $school->classrooms()->create($request->validated());

        return response()->json($classroom, 201);
    }

    /**
     * Display the specified resource.
     */
    public function show(School $school, Classroom $classroom)
    {
        return response()->json($classroom);
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(School $school, ClassroomRequest $request, Classroom $classroom)
    {
        $classroom->update($request->validated());

        return response()->json($classroom);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(School $school, Classroom $classroom)
    {
        $classroom->delete();

        return response()->json(null, 204);
    }
}
