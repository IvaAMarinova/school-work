<?php

use App\Http\Controllers\ClassroomController;
use App\Http\Controllers\SchoolController;
use App\Http\Controllers\StudentController;
use Illuminate\Support\Facades\Route;

Route::apiResource('schools', SchoolController::class);
Route::apiResource('schools.classrooms', ClassroomController::class);
Route::apiResource('schools.classrooms.students', StudentController::class);
