<?php

namespace App\Models;

use Database\Factories\SchoolFactory;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\HasMany;

class School extends Model
{
    /** @use HasFactory<SchoolFactory> */
    use HasFactory;

    protected $fillable = ['name', 'address', 'principal_name'];

    /**
     * @return HasMany
     */
    public function classrooms(): HasMany
    {
        return $this->hasMany(Classroom::class);
    }
}
