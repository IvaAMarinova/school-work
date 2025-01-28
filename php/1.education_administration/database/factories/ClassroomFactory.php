<?php

namespace Database\Factories;

use App\Models\Classroom;
use App\Models\School;
use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends Factory<Classroom>
 */
class ClassroomFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        return [
            'room_number' => $this->faker->randomNumber(3),
            'grade' => $this->faker->randomElement([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]),
            'school_id' => School::factory(),
        ];
    }
}
