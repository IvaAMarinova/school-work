<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Attendance extends Model
{
    use HasFactory;

    protected $fillable = ['user_id', 'class_session_id', 'status'];

    public function classSession()
    {
        return $this->belongsTo(ClassSession::class);
    }

    public function user()
    {
        return $this->belongsTo(User::class);
    }
}
