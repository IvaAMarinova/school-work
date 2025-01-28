<?php

namespace App\Http\Controllers;

use App\Http\Requests\StudentRequest;
use App\Http\Requests\UpdateStudentRequest;
use App\Models\Classroom;
use App\Models\School;
use App\Models\Student;

class StudentController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index(School $school, Classroom $classroom)
    {
        return response()->json($classroom->students);
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(School $school, Classroom $classroom, StudentRequest $request)
    {
        $student = $classroom->students()->create($request->validated());

        return response()->json($student, 201);
    }

    /**
     * Display the specified resource.
     */
    public function show(School $school, Classroom $classroom, Student $student)
    {
        return response()->json($student);
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(School $school, Classroom $classroom, StudentRequest $request, Student $student)
    {
        $student->update($request->validated());

        return response()->json($student);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(School $school, Classroom $classroom, Student $student)
    {
        $student->delete();

        return response()->json(null, 204);
    }
}
