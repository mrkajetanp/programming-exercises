package com.example.android.sunshine;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class DetailActivity extends AppCompatActivity {

    private static final String FORECAST_SHARE_HASHTAG = " #SunshineApp";

    private TextView mWeatherForecast;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);

        mWeatherForecast = (TextView) findViewById(R.id.tv_weather_forecast);

        Intent originIntent = getIntent();

        if (originIntent != null) {
            if (originIntent.hasExtra(Intent.EXTRA_TEXT))
                mWeatherForecast.setText(originIntent.getStringExtra(Intent.EXTRA_TEXT));
        }
    }
}