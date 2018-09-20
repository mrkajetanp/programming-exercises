package com.example.android.background.sync;

import android.content.Context;

import com.example.android.background.utilities.PreferenceUtilities;

public class ReminderTasks {
    public static final String ACTION_INCREMENT_WATER_COUNT = "increment_water_count";

    public static void executeTask(Context context,String action) {
        if (action.equals(ACTION_INCREMENT_WATER_COUNT))
            incrementWaterCount(context);
    }

    private static void incrementWaterCount(Context context) {
        PreferenceUtilities.incrementWaterCount(context);
    }

}
