<?php

use App\Models\School;

test('can fetch all schools', function () {
    $response = $this->getJson('/api/schools');
    $response->assertStatus(200);
})->group('schools');

test('can create a school', function () {
    $schoolData = ['name' => '31vo', 'address' => 'nqkude v geo milev', 'principal_name' => 'ne znam',];

    $response = $this->postJson('/api/schools', $schoolData);

    $response->assertStatus(201)
        ->assertJson($schoolData);
})->group('schools');

test('can view a specific school', function () {
    $school = School::factory()->create();

    $response = $this->getJson("/api/schools/{$school->id}");

    $response->assertStatus(200)
        ->assertJson(['id' => $school->id, 'name' => $school->name]);
})->group('schools');

test('can delete a school', function () {
    $school = School::factory()->create();

    $response = $this->deleteJson("/api/schools/{$school->id}");

    $response->assertStatus(204);
})->group('schools');

