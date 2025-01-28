<?php

namespace App\Models;

use Database\Factories\ClassroomFactory;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\BelongsTo;
use Illuminate\Database\Eloquent\Relations\HasMany;

class Classroom extends Model
{
    /** @use HasFactory<ClassroomFactory> */
    use HasFactory;

    protected $fillable = ['room_number', 'grade', 'school_id'];

    /**
     * @return BelongsTo
     */
    public function school(): BelongsTo
    {
        return $this->belongsTo(School::class);
    }

    /**
     * @return HasMany
     */
    public function students(): HasMany
    {
        return $this->hasMany(Student::class);
    }
}
