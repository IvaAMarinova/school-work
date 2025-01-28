<?php

use App\Models\Classroom;
use App\Models\Student;

test('can fetch students of a classroom', function () {
    $classroom = Classroom::factory()->create();
    Student::factory()->count(3)->for($classroom)->create();

    $response = $this->getJson("/api/schools/{$classroom->school_id}/classrooms/{$classroom->id}/students");

    $response->assertStatus(200)
        ->assertJsonCount(3);
})->group('students');

test('can create a student in a classroom', function () {
    $classroom = Classroom::factory()->create();
    $studentData = ['name' => 'Iva Marinova', 'age' => 18];

    $response = $this->postJson("/api/schools/{$classroom->school_id}/classrooms/{$classroom->id}/students", $studentData);

    $response->assertStatus(201)
        ->assertJson($studentData);
})->group('students');

test('can view a specific student', function () {
    $student = Student::factory()->create();

    $response = $this->getJson("/api/schools/{$student->classroom->school_id}/classrooms/{$student->classroom_id}/students/{$student->id}");

    $response->assertStatus(200)
        ->assertJson(['id' => $student->id, 'name' => $student->name]);
})->group('students');

test('can update a student', function () {
    $student = Student::factory()->create();
    $updatedData = ['name' => 'Iva M', 'age' => 17];

    $response = $this->putJson("/api/schools/{$student->classroom->school_id}/classrooms/{$student->classroom_id}/students/{$student->id}", $updatedData);

    $response->assertStatus(200)
        ->assertJson($updatedData);
})->group('students');

test('can delete a student', function () {
    $student = Student::factory()->create();

    $response = $this->deleteJson("/api/schools/{$student->classroom->school_id}/classrooms/{$student->classroom_id}/students/{$student->id}");

    $response->assertStatus(204);
})->group('students');