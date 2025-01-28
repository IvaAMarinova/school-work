<?php

namespace Database\Seeders;

use App\Models\Classroom;
use App\Models\School;
use App\Models\Student;
use Illuminate\Database\Seeder;

class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     */
    public function run(): void
    {
        $schools = School::factory()->count(3)->create();

        foreach ($schools as $school) {
            $rooms = Classroom::factory()->count(5)->create([
                'school_id' => $school->id,
            ]);

            foreach ($rooms as $room) {
                Student::factory()->count(20)->create([
                    'classroom_id' => $room->id,
                ]);
            }
        }
    }
}
