// App.tsx
import React, { useRef } from 'react';
import Header from './components/header';
import Footer from './components/footer';
import './App.css';
import Hair from './components/hair';
import Skin from './components/skin';
import Face from './components/face';
import Bronze from './components/bronze';
import Tan from './components/tan';
import HeroSection from './components/hero';
import Shine from './components/shine';
import SPF from './components/spf';
import Benefits from './components/benefits';
import SubscriptionForm from './components/subscription-form';
import CommentsSection from './components/comment-section';

function App() {
  // Create refs for each section
  const hairRef = useRef(null);
  const skinRef = useRef(null);
  const faceRef = useRef(null);
  const bronzeRef = useRef(null);
  const tanRef = useRef(null);
  const shineRef = useRef(null);
  const spfRef = useRef(null);

  return (
    <div className="flex flex-col min-h-screen bg-white text-gray-900">
      {/* Pass refs as props to Header */}
      <Header 
        refs={{
          hair: hairRef,
          skin: skinRef,
          face: faceRef,
          bronze: bronzeRef,
          tan: tanRef,
          shine: shineRef,
          spf: spfRef,
        }}
      />
      <HeroSection />
      <div ref={hairRef}><Hair /></div>
      <div ref={skinRef}><Skin /></div>
      <div ref={faceRef}><Face /></div>
      <div ref={bronzeRef}><Bronze /></div>
      <div ref={tanRef}><Tan /></div>
      <div ref={shineRef}><Shine /></div>
      <div ref={spfRef}><SPF /></div>
      <Benefits />
      <SubscriptionForm />
      <CommentsSection />
      <Footer />
    </div>
  );
};

export default App;
