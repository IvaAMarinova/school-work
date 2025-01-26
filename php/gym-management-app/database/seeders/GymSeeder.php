<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use App\Models\Gym;

class GymSeeder extends Seeder
{
    public function run()
    {
        Gym::create([
            'name' => 'Downtown Fitness',
            'address' => '123 Main St, Springfield',
        ]);

        Gym::create([
            'name' => 'Uptown Gym',
            'address' => '456 High St, Springfield',
        ]);

        Gym::create([
            'name' => 'City Center Wellness',
            'address' => '789 Elm St, Springfield',
        ]);
    }
}

