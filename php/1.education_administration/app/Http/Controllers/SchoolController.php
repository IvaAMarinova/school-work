<?php

namespace App\Http\Controllers;

use App\Http\Requests\SchoolRequest;
use App\Http\Requests\UpdateSchoolRequest;
use App\Models\School;

class SchoolController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        return response()->json(School::all());
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(SchoolRequest $request)
    {
        $school = School::create($request->validated());

        return response()->json($school, 201);
    }

    /**
     * Display the specified resource.
     */
    public function show(School $school)
    {
        return response()->json($school);
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(SchoolRequest $request, School $school)
    {
        $school->update($request->validated());

        return response()->json($school);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(School $school)
    {
        $school->delete();

        return response()->json(null, 204);
    }
}
