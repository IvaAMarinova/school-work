<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class ClassSession extends Model
{
    use HasFactory;

    protected $fillable = ['session_name', 'schedule', 'gym_id'];

    public function gym()
    {
        return $this->belongsTo(Gym::class);
    }

    public function attendance()
    {
        return $this->hasMany(Attendance::class);
    }
}
