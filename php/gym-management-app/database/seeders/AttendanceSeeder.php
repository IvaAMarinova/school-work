<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use App\Models\Attendance;
use App\Models\ClassSession;
use App\Models\User;

class AttendanceSeeder extends Seeder
{
    public function run()
    {
        $users = User::all();
        $classSessions = ClassSession::all();

        foreach ($classSessions as $classSession) {
            foreach ($users as $user) {
                Attendance::create([
                    'user_id' => $user->id,
                    'class_session_id' => $classSession->id,
                    'status' => rand(0, 1) ? 'present' : 'absent', // Randomize attendance
                ]);
            }
        }
    }
}
