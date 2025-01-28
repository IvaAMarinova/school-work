<?php

namespace App\Models;

use Database\Factories\StudentFactory;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\BelongsTo;

class Student extends Model
{
    /** @use HasFactory<StudentFactory> */
    use HasFactory;

    protected $fillable = ['name', 'age', 'classroom_id'];

    /**
     * @return BelongsTo
     */
    public function classroom(): BelongsTo
    {
        return $this->belongsTo(Classroom::class);
    }
}
