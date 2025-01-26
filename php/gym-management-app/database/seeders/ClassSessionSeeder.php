<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use App\Models\ClassSession;
use App\Models\Gym;

class ClassSessionSeeder extends Seeder
{
    public function run()
    {
        $gyms = Gym::all();

        foreach ($gyms as $gym) {
            ClassSession::create([
                'session_name' => 'Yoga Basics',
                'schedule' => now()->addDays(1)->format('Y-m-d H:i:s'),
                'gym_id' => $gym->id,
            ]);

            ClassSession::create([
                'session_name' => 'HIIT Workout',
                'schedule' => now()->addDays(2)->format('Y-m-d H:i:s'),
                'gym_id' => $gym->id,
            ]);

            ClassSession::create([
                'session_name' => 'Zumba Dance',
                'schedule' => now()->addDays(3)->format('Y-m-d H:i:s'),
                'gym_id' => $gym->id,
            ]);
        }
    }
}
